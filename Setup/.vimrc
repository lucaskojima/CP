"Editor settings
set nocp nu rnu ts=4 sw=4 si lbr so=5 bs=2 ru sc wmnu ic mouse=a bg=light
filetype plugin indent on
syntax on

"Keybinds
inoremap {<CR> {<CR>}<Esc>O
nnoremap <C-a> <Esc>ggVG<CR>
vnoremap <C-c> "+y
nnoremap <C-v> "+p
nnoremap <TAB> %

"Compile and Run
autocmd filetype cpp nnoremap <F1> :w <bar> !g++ % -std=c++17 -O2 -Wall -Wextra -Wshadow -Wconversion -Wfloat-equal -Wduplicated-cond -Wlogical-op -fsanitize=undefined -fsanitize=address -o %< <CR>
autocmd filetype cpp nnoremap <F2> :!./%< <CR>

"Template
autocmd BufNewFile *.cpp 0r /home/kojima/CP/library/template.cpp
