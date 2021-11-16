#!/usr/bin/python3
import os

# def file_name(file_dir):
#     for root, dirs, files in os.walk(file_dir):
#         print("root dirs")
#         print(root) #当前目录路径
#         print("child dirs")
#         print(dirs) #当前路径下所有子目录
#         print("child files")
#         print(files) #当前路径下所有非目录子文件
# file_name("/home/meizu/dailybuild2/DailyBuildM2191/app/国内版/Android11_Flyme9_M2191/QSSI_QRF9_base/userdebug/20211102150559_I/bin/QFIL")

# def file_name(file_dir):
#     L=[]
#     for root, dirs, files in os.walk(file_dir):
#         for file1 in files:
#             if os.path.splitext(file1)[1] == '.xml':
#                 L.append(os.path.join(root, file1))
#     return L

# xml_file = file_name("/home/meizu/dailybuild2/DailyBuildM2191/app/国内版/Android11_Flyme9_M2191/QSSI_QRF9_base/userdebug/20211102150559_I/bin/QFIL")
# print(xml_file)

def find_xml_files(file_dir):
    rawprogram_files = []
    for root, dirs, files in os.walk(file_dir):
        for file1 in files:
            print(os.path.splitext(file1)[0].find("rawprogram"))
            if os.path.splitext(file1)[0].find("rawprogram") != -1 and os.path.splitext(file1)[1] == '.xml':
                rawprogram_files.append(os.path.join(root, file1))
    return rawprogram_files

xml_file = find_xml_files("/home/meizu/dailybuild2/DailyBuildM2191/app/国内版/Android11_Flyme9_M2191/QSSI_QRF9_base/userdebug/20211102150559_I/bin/QFIL")
print(xml_file)
