#!/bin/bash
echo start
cd dogeub
echo running...
docker build -t doge .
docker run -d \
  --name dogeub \
  --restart unless-stopped \
  -p 3000:3000 \
  -e NODE_ENV=production \
  -e PORT=3000 \
  ghcr.io/xorynix/dogeub:latest
