set NAME skin
set SLICE_ORDER is
set ROWS 470
set COLUMNS 500
set STUDY ../slices/frog
set PIXEL_SIZE 1
set SPACING 1.5
set START_SLICE 1
set END_SLICE 138
set VOI "0 499 0 469 $START_SLICE $END_SLICE"
set VALUE 10.5
set SAMPLE_RATE "2 2 1"
set DECIMATE_REDUCTION .95
set DECIMATE_ITERATIONS 10
set DECIMATE_ERROR .0002
set DECIMATE_ERROR_INCREMENT .0002
set SMOOTH_ITERATIONS 0
set FEATURE_ANGLE 60

source marching8.tcl
