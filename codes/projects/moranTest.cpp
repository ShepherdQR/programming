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





int user_data;

float compute_moran(const pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_in, const pcl::PointCloud<pcl::Normal>::Ptr cloud_normals_in, const int cloudSize){
	
	float curvature_ave(0);
	for (size_t ii = 0; ii < cloudSize; ++ii){
		curvature_ave += cloud_normals_in->points[ii].curvature;
	}
	
	float curvature_ns(0);
	for (size_t jj = 0; jj < cloudSize; ++jj){
		curvature_ns += pow(( cloud_normals_in->points[jj].curvature - curvature_ave) ,2) ;
	}

	float moran_up(0), moran_down(0), w_ij(0);
	for (size_t i = 0; i < cloudSize; ++i){
		for (size_t j = 0; j < cloudSize; ++j){
			w_ij = pow( ( pow((cloud_in->points[i].x - cloud_in->points[j].x), 2) 
			+ pow((cloud_in->points[i].y - cloud_in->points[j].y), 2) 
			+ pow((cloud_in->points[i].z - cloud_in->points[j].z), 2)    ) , 0.5) * ( cloud_normals_in->points[i].curvature - curvature_ave);
			moran_up += w_ij * ( cloud_normals_in->points[j].curvature - curvature_ave);
			moran_down += w_ij * curvature_ns;
		}
	}
	
	float moran_out(0);
	moran_out = (float)cloudSize * moran_up / moran_down;
	//moran_out = cloud_in->points[0].y;//ok
	//moran_out = cloud_normals_in->points[0].curvature;//ok
	//moran_out = curvature_ave;//ok


}


void
compute_normal( const pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_tgt, std::vector<int> indices_in_real,   const pcl::PointCloud<pcl::Normal>::Ptr cloud_tgt_normals, const int RadiusSearch  ){
    pcl::removeNaNFromPointCloud(*cloud_tgt, *cloud_tgt, indices_in_real);
    pcl::NormalEstimation<pcl::PointXYZRGB, pcl::Normal> ne_tgt;
    ne_tgt.setInputCloud(cloud_tgt);
    pcl::search::KdTree< pcl::PointXYZRGB>::Ptr tree_tgt(new pcl::search::KdTree< pcl::PointXYZRGB>());
    ne_tgt.setSearchMethod(tree_tgt);
    ne_tgt.setRadiusSearch( 15);
    ne_tgt.compute(*cloud_tgt_normals);
	cout << "ok" << endl;
}


void viewerPsycho(pcl::visualization::PCLVisualizer& viewer){
	static unsigned count = 0;
	std::stringstream ss;
	ss << "Once per viewer loop: " << count++;
	viewer.removeShape("text", 0);
	viewer.addText(ss.str(), 100, 400, "text", 0);
	user_data++;
	cout << "ok" << endl;
}






int main(int argc, char ** argv){

	// Variable Initialization =========================
	pcl::PointCloud<pcl::PointXYZ>::Ptr  cloudxyzrgb_target_ori1(new pcl::PointCloud<pcl::PointXYZ>);

	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloudxyzrgb_target_ori(new pcl::PointCloud<pcl::PointXYZRGB>),
	cloudxyzrgb_target_centroid(new pcl::PointCloud<pcl::PointXYZRGB>);

	


	pcl::visualization::PCLVisualizer viewer3("Step 02 c");
	int v31(0),v32(1),v33(2),v34(3);
	viewer3.setBackgroundColor(255, 255, 255);// 255 *3 = white
	


    string file_name = "/home/jellyfish/datasets/bunny/reconstruction/bun_zipper_res3.ply";
	// res4 = 453
	pcl::io::loadPLYFile(file_name, *cloudxyzrgb_target_ori1 );


	//string file_name = "/home/jellyfish/datasets/bunny/bun0.pcd";
	//pcl::PCDReader reader;
	//reader.read(file_name, *cloudxyzrgb_target_ori1);

	pcl::copyPointCloud(*cloudxyzrgb_target_ori1, *cloudxyzrgb_target_ori );


	Eigen::Vector4f centroid_final_vox_mls;
	compute3DCentroid(*cloudxyzrgb_target_ori , centroid_final_vox_mls);
	Eigen::Affine3f transform_2 = Eigen::Affine3f::Identity();
	transform_2.translation() =-1*centroid_final_vox_mls.head(3);
	pcl::transformPointCloud (*cloudxyzrgb_target_ori, *cloudxyzrgb_target_centroid, transform_2);




	
	
	


	std::vector<int> indices_target_real_left;
    pcl::PointCloud<pcl::Normal>::Ptr target_normals(new pcl::PointCloud< pcl::Normal>);
	compute_normal(cloudxyzrgb_target_centroid, indices_target_real_left,target_normals ,0.02 );//searchRadius
	
	int size_cloud_centroid = -1;
	size_cloud_centroid = cloudxyzrgb_target_centroid->points.size ();
	cout << size_cloud_centroid  << endl;

	int size_normal = -1;
	size_normal = target_normals->points.size ();
	cout << "hi" << size_normal  << endl;



	float moran = compute_moran(cloudxyzrgb_target_centroid, target_normals, size_cloud_centroid);

	cout << moran << endl;






	viewer3.addPointCloud(cloudxyzrgb_target_centroid, "cloud_template_v31", v31);
	viewer3.setPointCloudRenderingProperties( pcl::visualization::RenderingProperties::PCL_VISUALIZER_POINT_SIZE, 5, "cloud_template_v31" );
	//viewer3.addText("RegionGrowing of filterd cloud", 10, 10, "RegionGrowing of filterd cloud", v31);
	




	while (!viewer3.wasStopped())
	{
		viewer3.spinOnce();
	}
	return 0;

}
