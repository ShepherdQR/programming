/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-03-07 22:44:30
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-03-07 23:29:29
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/



#include <iostream>
#include<vector>
#include <string>


//-------------------------pcl
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>


using namespace std;
// --------------------

void FilterVoxelGrid(const pcl::PointCloud<pcl::PointXYZRGBA>::Ptr CloudIn, const float LeafSizeVoxel, pcl::PointCloud<pcl::PointXYZRGBA>::Ptr CloudOut);




//====================
int main(int argc, char **argv){

    //------------ load initialization
    ifstream information("../Initialization.qr");
    string file_temp;
    vector <string> file_inf;
    while(getline(information, file_temp)){
        if( file_temp.find("/")==-1 ||  file_temp.find("/")>=2   ){
            //cout<< file_temp;
            file_inf.push_back(file_temp);
        }
    }//cout << endl;
    string FileName = file_inf[0];
    //cout << FileName << endl;


    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr CloudOri(new pcl::PointCloud<pcl::PointXYZRGBA>),
    CloudVoxel(new pcl::PointCloud<pcl::PointXYZRGBA>);


    pcl::visualization::PCLVisualizer Viewer1("Filter Viewer");
    Viewer1.setBackgroundColor(255, 255, 255);// 255 *3 = white

    
    pcl::io::loadPCDFile(FileName, *CloudOri);
    Viewer1.addPointCloud(CloudOri, "CloudOri_zqr");



    //============ voxel grid...
    float LeafSizeVoxel1 = 0.01;
    FilterVoxelGrid(CloudOri, LeafSizeVoxel1, CloudVoxel);
    Viewer1.updatePointCloud(CloudVoxel, "CloudOri_zqr");








    //pcl::PolygonMesh mesh_try;
    //pcl::io::loadPLYFile(argv[1], mesh_try);//"output.ply"
    //viewer1.addPolygonMesh( mesh_try, "mesh_zqr");





    while (!Viewer1.wasStopped()){
		Viewer1.spinOnce();
	}
    return 0;
}



void FilterVoxelGrid(const pcl::PointCloud<pcl::PointXYZRGBA>::Ptr CloudIn, const float LeafSizeVoxel, pcl::PointCloud<pcl::PointXYZRGBA>::Ptr CloudOut){
    pcl::VoxelGrid<pcl::PointXYZRGBA> sor;
sor.setInputCloud (CloudIn);
sor.setLeafSize (LeafSizeVoxel,LeafSizeVoxel,LeafSizeVoxel);
sor.filter (*CloudOut);
}


