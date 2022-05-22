set nocompatible           
set scl=yes
set nu
filetype off                 

set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
	Plugin 'VundleVim/Vundle.vim'
	Plugin 'tpope/vim-fugitive'
	Plugin 'git://git.wincent.com/command-t.git'
	Plugin 'puremourning/vimspector'
	Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
	Plugin 'Yggdroot/indentLine'
	Plugin 'sheerun/vim-polyglot'
	Plugin 'ryanoasis/vim-devicons'
	Plugin 'ycm-core/YouCompleteMe'
call vundle#end()           
filetype plugin indent on   

let g:vimspector_enable_mappings = 'VISUAL_STUDIO'
packadd! vimspector
