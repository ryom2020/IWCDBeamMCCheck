#image=/home/ryom/disk2/software_container/softwarecontainer_v1.4.2.sif
image=/home/ryom/disk2/software_container/softwarecontainer_workshop.sif
#bindpath=/home/ryom,/home/ryom/disk2/softwares

#module load StdEnv/2020
module load apptainer/1.3.5
#singularity exec --bind $bindpath $image /bin/bash
apptainer exec $image /bin/bash
