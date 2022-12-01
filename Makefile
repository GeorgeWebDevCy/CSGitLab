all:
	gcc  -o pm pm.c
	gcc  -o create_project create_project.c
	gcc  -o add_feature add_feature.c
	gcc  -o add_tag add_tag.c
	gcc  -o find_tag find_tag.c
	gcc  -o move_by_tag move_by_tag.c
	mkdir programs
	mv create_project programs/create_project
	mv add_feature programs/add_feature
	mv add_tag programs/add_tag
	mv find_tag programs/find_tag
	mv move_by_tag programs/move_by_tag
	# I will create the folder as defined in the find_tag scenario
	mkdir one
	mkdir one/first
	mkdir one/last
	mkdir two
	mkdir three
	touch one/.pm_tag
	touch three/.pm_tag
	touch one/first/.pm_tag
	echo "F1" > one/.pm_tag
	echo "F3" > three/.pm_tag
	echo "F1.1" > one/first/.pm_tag
	cd ..
clean:
	rm -f rm -rf ./*/
	rm -f programs
	rm pm