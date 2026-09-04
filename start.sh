#!/bin/bash
echo start
cd dogeub
echo running...
docker run -d \
  --name doge_container \
  --restart unless-stopped \
  -p 3000:3000 \
  doge

