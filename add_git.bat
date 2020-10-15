@echo on

git status
pause
git init

echo "  Enter location  "
set /p string=
pause

git remote add origin "%string%"
git status
pause
