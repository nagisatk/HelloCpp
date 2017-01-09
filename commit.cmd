set /p commit=Input Commit Message: 
git add .
git commit -m "%commit%"
git push origin master