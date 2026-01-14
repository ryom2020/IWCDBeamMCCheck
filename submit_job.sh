#!/bin/bash
#
#SBATCH --job-name=test
#SBATCH --account=rpp-blairt2k
#SBATCH --output=log-%j.out
#SBATCH --error=log-%j.err
#
#SBATCH --ntasks=1
#SBATCH --mem-per-cpu=5g
#
#SBATCH --time=00:10:00
#                   

image=/home/ryom/disk2/software_container/softwarecontainer_workshop.sif
module load apptainer/1.3.5
apptainer exec $image /bin/bash

pwd
echo job start

apptainer exec $image ./job.sh

echo job end
 

