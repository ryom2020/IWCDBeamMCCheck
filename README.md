**How to use**

1. activate software container:
```
source exec_singularity.sh
```
2. compile:
```
source setenv.sh
make
```
3. submit jobs (need to deactivate singularity):
```
source submit_multi_jobs.sh
```
4. merge histograms:
```
source run_merge_hists.sh
```
Files will be generated under ./out

5. draw histograms:
```
./draw_hists ./out/hist_merge.root
```
Figures will be generated under ./figures

