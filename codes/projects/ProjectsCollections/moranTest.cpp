/*** 
 * @Author: Shepherd Qirong
 * @Date: 2020-02-19 21:16:59
 * @Github: https://github.com/ShepherdQR
 * @LastEditors: Shepherd Qirong
 * @LastEditTime: 2020-02-21 01:43:38
 * @Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

// moran'l try


#include <iostream>
#include <algorithm>
#include<iterator>
#include <vector>

#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>

#include <pcl/console/parse.h>
#include <pcl/console/time.h>   // TicToc
#include <pcl/common/transforms.h> 
#include <pcl/common/centroid.h>
#include <pcl/features/fpfh.h>
#include <pcl/features/normal_3d.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/filters/passthrough.h>
#include <pcl/filters/project_inliers.h>

#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/ModelCoefficients.h>

#include <pcl/registration/icp.h>
#include <pcl/registration/ia_ransac.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/search/search.h>
#include <pcl/search/kdtree.h>
#include <pcl/segmentation/region_growing.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/surface/mls.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/cloud_viewer.h>
#include <fstream>
#include <Eigen/Dense>
#include <string>
#include <ctime>

boost::mutex cloud_mutex;

using namespace std;
using Eigen::MatrixXd;



float compute_moran_curvatureVSxyz(const pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_in, const pcl::PointCloud<pcl::Normal>::Ptr cloud_normals_in, const int cloudSize);

float compute_moran_zVSxy(const pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_in, const int cloudSize);

void compute_normal( const pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_tgt, std::vector<int> indices_in_real,   const pcl::PointCloud<pcl::Normal>::Ptr cloud_tgt_normals, const int RadiusSearch);


bool computeCentroid = false;

int main(int argc, char ** argv){
	/*
	if (argc != 3){
    std::cerr << "Usage:  " << argv[0] << " [infile] [parameters: c, z]\n";
    return 1;
  }

  */

	// Variable Initialization =========================
	pcl::PointCloud<pcl::PointXYZ>::Ptr  cloudxyzrgb_target_ori1(new pcl::PointCloud<pcl::PointXYZ>);

	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloudxyzrgb_target_ori(new pcl::PointCloud<pcl::PointXYZRGB>),
	cloudxyzrgbTargetCentroid(new pcl::PointCloud<pcl::PointXYZRGB>);

	


	pcl::visualization::PCLVisualizer viewer3("Step 02 c");
	int v31(0),v32(1),v33(2),v34(3);
	viewer3.setBackgroundColor(255, 255, 255);// 255 *3 = white
	


    //string file_name = "/home/jellyfish/datasets/bunny/reconstruction/bun_zipper_res3.ply";// res4 = 453
	//pcl::io::loadPLYFile(file_name, *cloudxyzrgb_target_ori1 );


	//string file_name = "../datasets/p0.pcd";
	string file_name = "../datasets/err.pcd";
	// res4 = 453
	pcl::io::loadPCDFile(file_name, *cloudxyzrgb_target_ori1 );


	//string file_name = "/home/jellyfish/datasets/bunny/bun0.pcd";
	//pcl::PCDReader reader;
	//reader.read(file_name, *cloudxyzrgb_target_ori1);

	pcl::copyPointCloud(*cloudxyzrgb_target_ori1, *cloudxyzrgb_target_ori );

		// transform to centroid	if(computeCentroid == true)
	Eigen::Vector4f centroid_final_vox_mls;
	compute3DCentroid(*cloudxyzrgb_target_ori , centroid_final_vox_mls);
	Eigen::Affine3f transform_2 = Eigen::Affine3f::Identity();
	if(computeCentroid == true)
		transform_2.translation() =-1*centroid_final_vox_mls.head(3);
	pcl::transformPointCloud (*cloudxyzrgb_target_ori, *cloudxyzrgbTargetCentroid, transform_2);

		// calculate normals
	std::vector<int> indices_target_real_left;
    pcl::PointCloud<pcl::Normal>::Ptr targetCenteroidNormals(new pcl::PointCloud< pcl::Normal>);
	compute_normal(cloudxyzrgbTargetCentroid, indices_target_real_left,targetCenteroidNormals ,0.02 );//searchRadius


	int size_cloud_centroid = -1;
	size_cloud_centroid = cloudxyzrgbTargetCentroid->points.size ();
	cout << "Point Numbers: " << size_cloud_centroid  << endl;
	//int size_normal = -1;
	//size_normal = targetCenteroidNormals->points.size ();
	//cout << "Point Numbers: " << size_normal  << endl;




	float moran = compute_moran_curvatureVSxyz(cloudxyzrgbTargetCentroid, targetCenteroidNormals, size_cloud_centroid);
	//float moran = compute_moran_zVSxy(cloudxyzrgbTargetCentroid , size_cloud_centroid);
	cout << "Moran's I:" << moran << endl;





	viewer3.addPointCloud(cloudxyzrgbTargetCentroid, "cloud_template_v31", v31);
	viewer3.setPointCloudRenderingProperties( pcl::visualization::RenderingProperties::PCL_VISUALIZER_POINT_SIZE, 5, "cloud_template_v31" );
	//viewer3.addText("RegionGrowing of filterd cloud", 10, 10, "RegionGrowing of filterd cloud", v31);
	


	while (!viewer3.wasStopped())
	{
		viewer3.spinOnce();
	}
	return 0;

}






float compute_moran_curvatureVSxyz(const pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_in, const pcl::PointCloud<pcl::Normal>::Ptr cloud_normals_in, const int cloudSize){

	float curvature_ave(0);
	vector< vector<float> > weight(cloudSize, vector<float> (cloudSize, 0));

	for (size_t i = 0; i < cloudSize; ++i){
		curvature_ave += cloud_normals_in->points[i].curvature;

		float w_normalization(0);
		for (size_t j = 0; j < cloudSize; ++j){
			if(i == j)
				weight[i][j] = 0;
			else 
				weight[i][j] = pow( ( 
					pow((cloud_in->points[i].x - cloud_in->points[j].x), 2) 
					+ pow((cloud_in->points[i].y - cloud_in->points[j].y), 2)
					+ pow((cloud_in->points[i].z - cloud_in->points[j].z), 2)
				), 1.0*0.5);//-3.0 *0.5 turns out to be 0.999
			
			w_normalization += weight[i][j];
		}

		for (size_t j = 0; j < cloudSize; ++j){
			if(w_normalization == 0)
				weight[i][j] = 0;
			else{
				if(i == j)
					weight[i][j] = 0;
				else
					weight[i][j] /=w_normalization;
			}
		}
	}

	
	float curvature_ns(0);
	for (size_t jj = 0; jj < cloudSize; ++jj){
		curvature_ns += pow(( cloud_normals_in->points[jj].curvature - curvature_ave) ,2) ;
	}

	float moran_up(0), moran_down(0);
	for (size_t i = 0; i < cloudSize; ++i){
		for (size_t j = 0; j < cloudSize; ++j){
			
			moran_up += weight[i][j] 
			* ( cloud_normals_in->points[i].curvature - curvature_ave)
			* ( cloud_normals_in->points[j].curvature - curvature_ave);
			moran_down += weight[i][j] * curvature_ns;
		}
	}

	float moran_out(0);
	moran_out = (float)cloudSize * moran_up / moran_down;
	//moran_out = cloud_in->points[0].y;//ok
	//moran_out = cloud_normals_in->points[0].curvature;//ok
	//moran_out = curvature_ave;//ok
}



float compute_moran_zVSxy(const pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_in, const int cloudSize){

	float z_ave(0);
	vector< vector<float> > weight(cloudSize, vector<float> (cloudSize, 0));

	for (size_t i = 0; i < cloudSize; ++i){
		z_ave += cloud_in->points[i].z;

		float w_normalization(0);
		for (size_t j = 0; j < cloudSize; ++j){
			weight[i][j] = pow( ( 
				pow((cloud_in->points[i].x - cloud_in->points[j].x), 2) 
				+ pow((cloud_in->points[i].y - cloud_in->points[j].y), 2)
				+ pow((cloud_in->points[i].z - cloud_in->points[j].z), 2)
			), -3.0*0.5);
			if(i != j){
				w_normalization += weight[i][j];
			}
		}

		for (size_t j = 0; j < cloudSize; ++j){
			if(w_normalization == 0)
				weight[i][j] = 0;
			else{
				if(i == j)
					weight[i][j] = 0;
				else
					weight[i][j] /=w_normalization;
			}
		}
	}

	float z_ns(0);
	for (size_t jj = 0; jj < cloudSize; ++jj){
		z_ns += pow(( cloud_in->points[jj].z - z_ave) ,2) ;
	}

	float moran_up(0), moran_down(0);
	for (size_t i = 0; i < cloudSize; ++i){
		for (size_t j = 0; j < cloudSize; ++j){
			moran_up += weight[i][j]
			*( cloud_in->points[i].z - z_ave)
			*( cloud_in->points[j].z - z_ave);
			moran_down += weight[i][j] * z_ns;
		}
	}
	
	float moran_out(0);
	moran_out = (float)cloudSize * moran_up / moran_down;

}



void compute_normal( const pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_tgt, std::vector<int> indices_in_real,   const pcl::PointCloud<pcl::Normal>::Ptr cloud_tgt_normals, const int RadiusSearch){
    pcl::removeNaNFromPointCloud(*cloud_tgt, *cloud_tgt, indices_in_real);
    pcl::NormalEstimation<pcl::PointXYZRGB, pcl::Normal> ne_tgt;
    ne_tgt.setInputCloud(cloud_tgt);
    pcl::search::KdTree< pcl::PointXYZRGB>::Ptr tree_tgt(new pcl::search::KdTree< pcl::PointXYZRGB>());
    ne_tgt.setSearchMethod(tree_tgt);
    ne_tgt.setRadiusSearch( 15);
    ne_tgt.compute(*cloud_tgt_normals);
	cout << "ok" << endl;
}