# Attribute-Based-Access-Control
Dataset Description:

10 subject attributes with first 5 having mutually exclusive values
8 object attributes with first 4 having mutually exclusive values

n=no. of subjects, m=no. of objects
to vary (nxm), vary r1 and r2 in Dataset.cpp ; The generated dataset will appear in Data.txt which serves as input for PolicyMine.cpp

To run:
1) First Run Dataset.cpp to generate data.txt
2) data.txt becomes input for PolicyMine.cpp
3) Run PolicyMine.cpp
4) Rules appear in Output.txt
5) A new file Statistics.txt gets created which will store time taken and no. of rules.
6) Vary nxm in Dataset.cpp and follow all steps again.

To visualize for a small dataset, Input.txt contents should be copied to data.txt and PolicyMine.cpp should be run. Here, merging is more visible

System Info:
Laptop: ASUS-TUF-GAMING
Further specifications can be seen in "System Info.png"
