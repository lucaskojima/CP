"Pluggins
call plug#begin()

Plug 'SirVer/ultisnips'
let g:UltiSnipsExpandTrigger="<tab>"

Plug 'tpope/vim-dispatch'

call plug#end()

"Editor settings
set nocp nu rnu ts=4 sw=4 si lbr so=5 bs=2 ru sc wmnu ic mouse=a
filetype plugin indent on
syntax on

"Keybinds
inoremap {<CR> {<CR>}<Esc>O
nnoremap <C-a> <Esc>ggVG<CR>
vnoremap <C-c> "+y
nnoremap <C-v> "+p
nnoremap <TAB> %

nnoremap <F1> <nop>
inoremap <F1> <nop>

"Compile and Run
set makeprg=g++\ -std=c++17\ -O2\ -Wall\ %\ -o\ %<
autocmd filetype cpp nnoremap <F1> :w <bar> Make <CR>
autocmd filetype cpp nnoremap <F2> :vertical terminal ./%< <CR>
autocmd filetype cpp nnoremap <F3> :!./%< <CR>

"Template
autocmd BufNewFile *.cpp 0r /home/kojima/CP/library/template.cpp
