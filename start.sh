#!/bin/bash
echo start.sh: start
sudo tailscaled && echo start.sh: tailscaled started & sudo tailscale up & echo start.sh: tailscale up & cd dogeub & echo start.sh: running...  & docker build -t doge .  &  docker run -p 0.0.0.0:3000:3000 doge && bash
