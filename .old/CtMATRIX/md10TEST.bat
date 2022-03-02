for /L %%i IN (1,1,9) Do (MD TEST0%%i && CD TEST0%%i && break>"CTMATRIX.INP" && break>"CTMATRIX.OUT" && CD ..)
MD TEST10
CD TEST10
break>"CTMATRIX.INP" 
break>"CTMATRIX.OUT"
