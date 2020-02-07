#!/bin/bash

## last modified on 2020020717:58



#------ file is saved with number $1
id_in=$1
#echo $id_in

id_i=$id_in
file_name=qr
for ((i=1; i<=4; ++i)); do
    file_name=$((id_i%10))$file_name
    id_i=$((id_i/(10**1)))
    #echo $id_i
    #echo $file_name
done
if ((id_i>0)); then
   file_name=$id_i$file_name
fi

file_name=opengl$file_name
echo $file_name

if [ ! -d $file_name ]; then
    mkdir $file_name
else
    echo "folder $file_name exists..."
fi
#------




#------ match the build+date folder
project_path=$(cd `dirname $0`; pwd)
build_name=${project_path##*/}
#echo $build_name

all_files=$(ls)
for one_file in $all_files
do
    #echo $one_file
    if [[ $one_file == build* ]]; then
        build_folder=$one_file
    fi
    if [[ ${one_file: -4} == .cpp ]]; then
        main_cpp_name=$one_file
    fi
done
echo $build_folder
#------



cp $build_folder/main $file_name
cp $main_cpp_name $file_name
cp glad.c $file_name
cp CMakeLists.txt $file_name




cd $file_name
#touch "$file_name"_log.txt
current2=`date "+%Y%m%d%H%M%S"`

echo "File $main_cpp_name is modified on: $current2, while the is built on: $build_folder." >> "$file_name"_log.txt
