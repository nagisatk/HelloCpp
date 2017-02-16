del *.exe
set /p commit=Input Commit Message: 
git add basic*
git commit -m "%commit%"
git push origin master

pause