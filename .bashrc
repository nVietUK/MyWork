rm -rf ~/.cache/*

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
