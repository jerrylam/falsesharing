# Disclaimer
I wrote this at work for fun but at the end I want to keep it so here it is.

# False Sharing Performance Demonstration
This docker image will demonstrate the effect of false sharing for a multithread program. 

# Build the image
```
docker build -t "falsesharing" .
```
# Run the image
```
docker run -it falsesharing
```

## Sample Outputs
```
=============================
Parallelism: 1, Type:FALSE_SHARING
Duration (milliseconds): 3644
=============================
Parallelism: 2, Type:FALSE_SHARING
Duration (milliseconds): 6494
=============================
Parallelism: 3, Type:FALSE_SHARING
Duration (milliseconds): 8357
=============================
Parallelism: 4, Type:FALSE_SHARING
Duration (milliseconds): 9676
=============================
Parallelism: 5, Type:FALSE_SHARING
Duration (milliseconds): 7433
=============================
Parallelism: 6, Type:FALSE_SHARING
Duration (milliseconds): 6321
=============================
Parallelism: 7, Type:FALSE_SHARING
Duration (milliseconds): 5739
=============================
Parallelism: 1, Type:NO_SHARING
Duration (milliseconds): 3702
=============================
Parallelism: 2, Type:NO_SHARING
Duration (milliseconds): 1862
=============================
Parallelism: 3, Type:NO_SHARING
Duration (milliseconds): 1375
=============================
Parallelism: 4, Type:NO_SHARING
Duration (milliseconds): 1109
=============================
Parallelism: 5, Type:NO_SHARING
Duration (milliseconds): 1087
=============================
Parallelism: 6, Type:NO_SHARING
Duration (milliseconds): 1000
=============================
Parallelism: 7, Type:NO_SHARING
Duration (milliseconds): 993
```
