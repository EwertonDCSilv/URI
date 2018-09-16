@echo off 
gcc pa3.c -o v
FOR /L %%A IN (1,1,26) DO (
	ECHO ############### TESTE %%A ###############
	v.exe < A\A_%%A.txt  > A\resultado%%A.txt
	ECHO     ############### Resultaso %%A ########
	diff A\A_%%A.sol A\resultado%%A.txt
	ECHO #########################################
	ECHo.
)