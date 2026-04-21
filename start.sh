#!/bin/bash
echo start
cd dogeub
echo running...
dogeub = $(docker run -p 0.0.0.0:3000:3000 doge)
if [$dogeub != 0] then:
    echo building first...;
    docker build -t doge .;
    echo running...;
    docker run -p 0.0.0.0:3000:3000 doge;
    echo Done;
fi