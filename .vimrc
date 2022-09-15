 call plug#begin('~/.vim/plugged')
     Plug 'pbondoer/vim-42header'
 call plug#end()
 
 if has("syntax")
	 syntax on
 endif
 
 colorscheme jellybeans

 set smartindent
 set autoindent
 set cindent
 set ts=4
 set shiftwidth=4
 set sw=1
 set hlsearch
 set incsearch
 set showmatch
 set ruler
 set fileencodings=utf8,euc-kr
 set ts=4
 set listchars=tab:»\ ,extends:›,precedes:‹,nbsp:·,trail:·
 set nu

 let g:hdr42user = 'jiryu'
 let g:hdr42mail = 'jiryu@student.42seoul.kr'
