#!/bin/bash
echo start
cd dogeub
echo running...
docker build -t doge .
docker run -p 0.0.0.0:3000:3000 doge
