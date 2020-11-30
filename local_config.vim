com! -nargs=1 -complete=dir CMake !cmake --build <args> 2>&1 | tee errors.err

nnoremap <leader>mc :CMake make-clang<cr>:lf<cr>

nnoremap <leader>rp :!make-clang/playground 3<cr>

