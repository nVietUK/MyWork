set nocompatible           
filetype plugin indent on
set scl=yes
set nu

set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
	Plugin 'VundleVim/Vundle.vim'
	Plugin 'tpope/vim-fugitive'
	Plugin 'git://git.wincent.com/command-t.git'
	Plugin 'puremourning/vimspector'
	Plugin 'Yggdroot/indentLine'
	Plugin 'sheerun/vim-polyglot'
	Plugin 'ryanoasis/vim-devicons'
	Plugin 'neoclide/coc.nvim', {'branch': 'release'}
call vundle#end()           

let g:vimspector_enable_mappings = 'VISUAL_STUDIO'
set ts=4 sw=4 expandtab

nmap <silent> <leader>exit :VimspectorReset<CR>
