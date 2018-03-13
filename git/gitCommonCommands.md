## These are common Git commands used in various situations:

#### start a working area (see also: git help tutorial)
   clone      Clone a repository into a new directory
   init       Create an empty Git repository or reinitialize an existing one

#### work on the current change (see also: git help everyday)
   add        Add file contents to the index, "add ." adds all changes
   mv         Move or rename a file, a directory, or a symlink
   reset      Reset current HEAD to the specified state
   rm         Remove files from the working tree and from the index

#### examine the history and state (see also: git help revisions)
   bisect     Use binary search to find the commit that introduced a bug
   grep       Print lines matching a pattern
   log        Show commit logs
   show       Show various types of objects
   status     Show the working tree status

#### grow, mark and tweak your common history
   branch     List, create, or delete branches
   checkout   Switch branches or restore working tree files
   commit     Record changes to the repository
   diff       Show changes between commits, commit and working tree, etc
   merge      Join two or more development histories together
   rebase     Reapply commits on top of another base tip
   tag        Create, list, delete or verify a tag object signed with GPG

#### collaborate (see also: git help workflows)
   fetch      Download objects and refs from another repository
   pull       Fetch from and integrate with another repository or a local branch
   push       Update remote refs along with associated objects

'git help -a' and 'git help -g' list available subcommands and some
concept guides. See 'git help <command>' or 'git help <concept>'
to read about a specific subcommand or concept.



git clone --recurse-submodules https://<your repo address here>

git submodule update

git status

git diff

git difftool

#### Adds all changes recursively from the folder the command is issued
git add .

git commit -m "Your comment here"

#### Shows what branches are referenced and which is checked out
git branch
* APPS-135-uninitialized-variables
  APPS-163-convert-fovia-to-imfusion
  GPSD-480-rpsclientcontroller-uninitializ
  master
  master-candidate-Spine1-0-update

#### Tab completion works if the branch is already referenced, if the branch has never been
#### checked out, the exact name must be entered manually
git checkout <branch-name>

#### If you haven't committed changes you can remove specific files from the stage
git reset HEAD <file>