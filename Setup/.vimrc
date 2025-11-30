call plug#begin()

Plug 'tpope/vim-dispatch'

call plug#end()

set nocp nu rnu et ts=2 sw=2 ai nowrap so=5 bs=2 ru sc wmnu is mouse=a bg=light
filetype plugin indent on
syntax on

inoremap {<CR> {<CR>}<Esc>O
nnoremap <F1> <nop>
inoremap <F1> <nop>

set makeprg=g++\ -std=c++17\ -O2\ -Wall\ -Wextra\ -g3\ -fsanitize=address,undefined\ %\ -o\ %<
autocmd filetype cpp nnoremap <F1> :w <bar> Make <CR>
autocmd filetype cpp inoremap <F1> :w <bar> Make <CR>
autocmd filetype cpp nnoremap <F2> :!./%< <CR>
autocmd filetype cpp inoremap <F2> :!./%< <CR>

autocmd BufNewFile *.cpp 0r ~/cp/template.cpp
