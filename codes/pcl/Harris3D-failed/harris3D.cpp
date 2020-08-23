
/* 
3DHarris　 方块体内点数量变化确定角点
　　在2DHarris里，我们使用了 图像梯度构成的 协方差矩阵。 
    图像梯度。。。嗯。。。。每个像素点都有一个梯度，
    在一阶信息量的情况下描述了两个相邻像素的关系。显然这个思想可以轻易的移植到点云上来。
想象一下，如果在 点云中存在一点p
　　1、在p上建立一个局部坐标系：z方向是法线方向，x,y方向和z垂直。
　　2、在p上建立一个小正方体，不要太大，大概像材料力学分析应力那种就行
　　3、假设点云的密度是相同的，点云是一层蒙皮，不是实心的。
　　a、如果小正方体沿z方向移动，那小正方体里的点云数量应该不变
　　b、如果小正方体位于边缘上，则沿边缘移动，点云数量几乎不变，沿垂直边缘方向移动，点云数量改
　　c、如果小正方体位于角点上，则有两个方向都会大幅改变点云数量
　　如果由法向量x,y,z构成协方差矩阵，那么它应该是一个对称矩阵。
而且特征向量有一个方向是法线方向，另外两个方向和法线垂直。
　　那么直接用协方差矩阵替换掉图像里的M矩阵，就得到了点云的Harris算法。
　　其中，半径r可以用来控制角点的规模
　　r小，则对应的角点越尖锐（对噪声更敏感）
　　r大，则可能在平缓的区域也检测出角点
./harris3d ../../Filtering/build/table_scene_lms400_inliers.pcd 
*/
#include <iostream>
#include <boost/thread/thread.hpp>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>
//#include <pcl/keypoints/narf_keypoint.h>
#include <pcl/keypoints/harris_3d.h>
 
#include <cstdlib>
#include <vector>
using namespace std;
 
 
int 
main (int argc, char** argv){

  // 1 inialization   ==============
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloudOri(new pcl::PointCloud<pcl::PointXYZ>), cloudHarris(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZI>::Ptr cloudHarrisI (new pcl::PointCloud<pcl::PointXYZI>);

  // pcl::PointCloud<pcl::PointXYZI>& cloudHarrisI1 = *cloudHarrisI;
  // cloudHarrisI1.height=1;
  // cloudHarrisI1.width =100;
  // cloudHarrisI1.resize(cloudHarrisI1.height * cloudHarrisI1.width);    
  // cloudHarrisI1.clear();


  if (argc>=2)
  {
      pcl::io::loadPCDFile (argv[1], *cloudOri);
      cout << "load pcd file : "<< argv[1]<< endl;
      
  }
  else{
    pcl::io::loadPCDFile ( "/home/jellyfish/datasets/bunny/reconstruction/bunnyRe60269.pcd", *cloudOri);
  }
  cout << "Ori points number: " << cloudOri->points.size() << endl;



  // 2 harris 3d   ==============
  pcl::HarrisKeypoint3D<pcl::PointXYZ,pcl::PointXYZI,pcl::Normal> harris;
  harris.setInputCloud(cloudOri);
  harris.setRadius(0.1f);
  //harris.setThreshold(0.1f);
  harris.compute(cloudHarrisI1);

  for (size_t i = 0; i<cloudHarrisI->points.size(); ++i){    
    cloudHarris->points[i].x = cloudHarrisI->points[i].x;
    cloudHarris->points[i].y = cloudHarrisI->points[i].y;
    cloudHarris->points[i].z = cloudHarrisI->points[i].z;
  }
  cout << "Harris points number: " << cloudHarrisI->points.size() << endl;


  // 3  visualization  =============
  pcl::visualization::PCLVisualizer viewer ("3D Viewer");
  viewer.setBackgroundColor (1, 1, 1);

  viewer.addPointCloud(cloudOri, "ori");
  viewer.setPointCloudRenderingProperties( pcl::visualization::RenderingProperties::PCL_VISUALIZER_POINT_SIZE, 2, "ori");
  viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_COLOR, 0,0,0, "ori");

  viewer.addPointCloud(cloudHarris, "harris");
  viewer.setPointCloudRenderingProperties( pcl::visualization::RenderingProperties::PCL_VISUALIZER_POINT_SIZE, 6, "harris");
  viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_COLOR, 1,0,0, "harris");
  
  
 
  while (!viewer.wasStopped ())
  {
    viewer.spinOnce ();
  }
}




  /*
  else{
    cout << "\nNo *.pcd file given => Genarating example point cloud.\n\n";
    for (float x=-0.5f; x<=0.5f; x+=0.01f){
      for (float y=-0.5f; y<=0.5f; y+=0.01f){
        pcl::PointXYZ point;  point.x = x;  point.y = y;  point.z = 2.0f - y;
        point_cloud.points.push_back (point);//设置点云中点的坐标
      }
    }
    point_cloud.width = (int) point_cloud.points.size ();  
    point_cloud.height = 1;
  }
  */