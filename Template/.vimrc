set smarttab
set smartindent
set autoindent
set cindent
set tabstop=4
set shiftwidth=4
set linebreak
set number
syntax on
set background=dark
map <F6> :<C-U>!g++ %:r.cpp -o %:r<CR>
map <F7> :<C-U>!./%:r < input<CR>
