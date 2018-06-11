" == Vim Options ==
"source $VIMRUNTIME/vimrc_example.vim "Use this at school instead
source $VIMRUNTIME/defaults.vim "Some sensible defaults
"
"Looks
set linebreak "Break long lines at specific characters instead of anywhere
set number "Show line numbers
set display=lastline "Show as much as possible of a long line that doesn't fit on screen
set scrolloff=0 "When scrolling up/down always keep the cursor at least this many lines above/below the edge
syntax on

"set t_Co=16 "use on default windows terminal
colorscheme desert "use at school
set background=dark
"colorscheme default

"Typing Behaviour
set showmatch "Briefly jump to matching bracket when typing
set hlsearch
set wildmenu

"Formatting
set autoindent
set tabstop=4
set shiftwidth=4

"Technical
set encoding=utf-8

" == GVIM Options ==
if has('gui_running')
	set guifont=Consolas:h14:cANSI:qDRAFT
	set guicursor=a:block-Cursor
	set guicursor+=a:blinkon0
	set guioptions+=t "add cutout
	set guioptions-=T "remove toolbar
endif

" == Costum Keybindings ==
" Changing vim-Behaviour
nnoremap <CR> o<Esc>
nnoremap <S-CR> O<Esc>
map Y y$


" Adding Own Mappings
" With Leader
map <SPACE> <leader>

nnoremap <leader>author i/*Author: Benjamin BrandtnerPlatzhalter */#include <stdio.h>int main (void){Platzhalter;return 0;}/Platzhaltercw
nnoremap <leader>date a=strftime('%Y-%m-%d')

nnoremap <leader>n :noh<CR>
nnoremap <leader>! :<up><home><right>!<CR>

nnoremap <leader>c "+y
vnoremap <leader>c "+y
nnoremap <leader>v "+p
nnoremap <leader>V "+P

nnoremap <F10> :q<CR>
nnoremap <C-S> :w<CR>

" == Autocommands ==
"show trailing spaces in .md files 
autocmd BufRead,BufNewFile *.md set listchars=trail:',tab:\ \ 
autocmd BufRead,BufNewFile *.md set list

" == Makros ==

" == Kopierte Settings ==
" When editing a file, always jump to the last known cursor position.
" Don't do it when the position is invalid or when inside an event handler
" (happens when dropping a file on gvim).
if has("autocmd")
  autocmd BufReadPost *
    \ if line("'\"") >= 1 && line("'\"") <= line("$") |
    \   exe "normal! g`\"" |
    \ endif
endif " has("autocmd")

" ConEmu
if !has("gui_running")
    set term=xterm
    set t_Co=256
    let &t_AB="\e[48;5;%dm"
    let &t_AF="\e[38;5;%dm"
endif

" == Redundant Settings that are already in defaults.vim and probably
" vimrc_example
"set nocompatible
"set showcmd
"set ruler
"set mouse=a
