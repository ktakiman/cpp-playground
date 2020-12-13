com! -nargs=1 -complete=dir CMake !cmake --build <args> 2>&1 | tee errors.err

nnoremap <leader>mk :CMake make-clang<cr>:lf<cr>

nnoremap <leader>rn :!make-clang/playground 4<cr>

