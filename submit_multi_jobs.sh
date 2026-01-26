path_wcsim=/home/ryom/disk2/HK_beta_prod_IWCD/beta-production/iwcd/prod1A/validation/V01/neut536/t1/wcsim_v1.12.26_cwcs1.0/rwcs/
wcsimfilehead=lbl_neut_iwcd_test_00000000-
wcsimfilefoot=_rwcs.root

path_fq=/home/ryom/disk2/HK_beta_prod_IWCD/beta-production/iwcd/prod1A/validation/V01/neut536/t1/wcsim_v1.12.26_cwcs1.0/fitqun_6.4.4_cfqn1.0.0/rfqn/
fitqunfilehead=lbl_neut_iwcd_test_00000000-
fitqunfilefoot=_rfqn.root

path_workdir=/project/6008045/ryom/HK_beta_prod_IWCD/analysis/IWCDBeamMCCheck

path_outdir=$path_workdir/out

for wcsimfile in `ls $path_wcsim/*`
do
    key=${wcsimfile##*$wcsimfilehead}
    key=${key%$wcsimfilefoot}
    fitqunfile=$path_fq/$fitqunfilehead$key$fitqunfilefoot
    if [[ -f $fitqunfile ]]
    then
	mkdir -p $path_outdir/$key
	cd $path_outdir/$key
	echo '#!/bin/bash' > ./job.sh
    	echo source $path_workdir/setenv.sh >> ./job.sh
    	echo $path_workdir/fill_hist -w $wcsimfile -f $fitqunfile -o $path_outdir/$key/hist.root >> ./job.sh
	chmod +x ./job.sh
	sbatch $path_workdir/submit_job.sh
    fi

done
