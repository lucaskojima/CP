set nocp nu rnu et ts=2 sw=2 ai nowrap so=5 bs=2 ru sc wmnu is mouse=a bg=light
filetype plugin indent on
syntax on

inoremap {<CR> {<CR>}<Esc>O

autocmd BufNewFile *.cpp 0r ~/cp/template.cpp
