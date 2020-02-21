/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-02-22 00:03:02
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-02-22 01:14:00
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#include <iostream>
#include<vector>


//-------------------------pcl
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <string>

using namespace std;
// --------------------



// -------------
// Build a simple cube and write it to std::cout
  
int main(int argc, char **argv){

    // check command line options
  if (argc != 2) {
    std::cerr << "Usage:  " << argv[0] << " #iterations infile outfile\n";
    return 1;
  }

 
  pcl::visualization::PCLVisualizer viewer1("PLY Viewer");
	//pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGBA>);
  //viewer1.addPointCloud( cloud, "cloud_zqr");

  pcl::PolygonMesh mesh_try;

	pcl::io::loadPLYFile(argv[1], mesh_try);//"output.ply"
  viewer1.addPolygonMesh( mesh_try, "mesh_zqr");
 

	while (!viewer1.wasStopped()){
		viewer1.spinOnce();
	}



  return 0;
}
