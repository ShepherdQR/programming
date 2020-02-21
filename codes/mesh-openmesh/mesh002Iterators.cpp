/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2020-02-22 00:03:02
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2020-02-22 01:33:22
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/


/*
One smoothing iteration is done in two steps:

For each vertex: calculate the barycenter of its one-ring neighbors.
For each vertex: move the vertex to the computed barycenter.
*/




#include <iostream>
#include<vector>
// -------------------- OpenMesh
#include <OpenMesh/Core/IO/MeshIO.hh>
//#include <OpenMesh/Core/Mesh/PolyMesh_ArrayKernelT.hh>
//typedef OpenMesh::PolyMesh_ArrayKernelT<>  MyMesh;

#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
typedef OpenMesh::TriMesh_ArrayKernelT<>  MyMesh;

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

  MyMesh mesh;
    // check command line options
  if (argc != 4) {
    std::cerr << "Usage:  " << argv[0] << " #iterations infile outfile\n";
    return 1;
  }

    // read mesh from stdin
  if ( ! OpenMesh::IO::read_mesh(mesh, argv[2]) ){
    std::cerr << "Error: Cannot read mesh from " << argv[2] << std::endl;
    return 1;
  }

    // this vector stores the computed centers of gravity
  std::vector<MyMesh::Point>  cogs;
  std::vector<MyMesh::Point>::iterator cog_it;
  cogs.reserve(mesh.n_vertices());

    // smoothing mesh argv[1] times
  MyMesh::VertexIter          v_it, v_end(mesh.vertices_end());
  MyMesh::VertexVertexIter    vv_it;
  MyMesh::Point               cog;
  MyMesh::Scalar              valence;
  unsigned int                i, N(atoi(argv[1]));

  for (i=0; i < N; ++i)
  {
    cogs.clear();
    for (v_it=mesh.vertices_begin(); v_it!=v_end; ++v_it)
    {
      cog[0] = cog[1] = cog[2] = valence = 0.0;
      
      for (vv_it=mesh.vv_iter( *v_it ); vv_it.is_valid(); ++vv_it)
      {
        cog += mesh.point( *vv_it );
        ++valence;
      }
      cogs.push_back(cog / valence);
    }
    
    for (v_it=mesh.vertices_begin(), cog_it=cogs.begin(); 
         v_it!=v_end; ++v_it, ++cog_it)
      if ( !mesh.is_boundary( *v_it ) )
        mesh.set_point( *v_it, *cog_it );
  }

  // write mesh to stdout
  if ( ! OpenMesh::IO::write_mesh(mesh, argv[3]) )
  {
    std::cerr << "Error: cannot write mesh to " << argv[3] << std::endl;
    return 1;
  }



 

  return 0;
}
