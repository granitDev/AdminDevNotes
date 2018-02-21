// for all the changed files - do this from root git directory for project
git add .

// for specific files only
git add yourFile myFile ourFile etcFile/notYourfile

// after adding all changes, still in root of git project
git commit - m "your comment here"

// actually push files to repo
git push - u origin <branch name here, usually "master">

// update from repo
git fetch
git pull
