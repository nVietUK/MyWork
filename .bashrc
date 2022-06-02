powerline-daemon -q
POWERLINE_BASH_CONTINUATION=1
POWERLINE_BASH_SELECT=1
. /usr/lib/python3.10/site-packages/powerline/bindings/bash/powerline.sh

if [ -n "$SSH_CLIENT" ] || [ -n "$SSH_TTY" ]; then
  rm /home/nvietuk/MyWork/bin/*
  cd MyWork
  git add .
  git commit -m "`date`"
  git push
  clear
else
  iftop -i wlan0
fi
