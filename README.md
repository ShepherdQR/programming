

Started on 2002011920:23


1st upload to a new repository
enter the folder with the same name of the repository,then:

git init
git add .
git commit -m '1st_m'
git remote add origin git@github.com:ShepherdQR/programming.git
git push -u origin master -f


then upload to an old repository:

git init
git reomte add origin git@github.com:ShepherdQR/programming.git
get pull origin master
git add .
git commit -m '1st_m'
git push -u origin master
