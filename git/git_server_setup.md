Install git onto your server and your local machine.
Git is in the repositories of most major distros, 
so use of apt-get or dnf or yum should allow easy
installation of git on both machines.


####Setting up the remote server:
	mkdir -p foo/foo.git
	cd foo/foo.git
	git init --bare

####Setting up git on your local machine:
	mkdir -p foo
	cd foo
	git init

	if that worked you should see a .git directory in foo/
	if there is no .git directory, something when wrong

####Setting up your ssh keys, assuming you've already created them:
	cd ~.ssh/
	vi config
		Host <any_name_you_like>
		        User <actual_user_name_on_remote_server>
			HostName <IP_address_DNS_name_etc>
		        IdentityFile ~/.ssh/your_key_file

####Setting up your local machint to talk to the remote for the first time:
	/foo $ git remote add *any_name_you_like* user@server:foo.git
	/foo $ touch test.file
	/foo $ git add test.file && git commit -m "your comment" test.file
	/foo $ git push --set-upstream username@ssh_config_host:foo.git master
