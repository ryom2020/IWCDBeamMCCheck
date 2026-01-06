#!/bin/bash
#
#SBATCH --job-name=test
#SBATCH --account=def-blairt2k
#SBATCH --output=job-%j.out
#SBATCH --error=job-%j.err
#
#SBATCH --ntasks=1
#SBATCH --mem-per-cpu=5g
#
#SBATCH --time=72:00:00
#                   

image=/home/ryom/disk2/software_container/softwarecontainer_workshop.sif
#bindpath=/home/ryom,/home/ryom/disk2/softwares
#module load StdEnv/2020   
module load apptainer/1.3.5
apptainer exec $image /bin/bash

echo job start
pwd

apptainer exec $image job.sh

echo job end
 

