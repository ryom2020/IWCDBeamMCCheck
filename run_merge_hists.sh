#!/bin/bash
hists=`ls -v out/*/*.root`
./merge_hists ./out/hist_merged.root $hists
