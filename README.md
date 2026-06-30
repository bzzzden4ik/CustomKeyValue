# Append Custom Key-value storage (now in progress)

### Main idea - create my own append key-value storage like Redis.
### This project was made for educational purpose but it also can be used as main key-value storage for your projects.

## Why do I need it?

* Use it for your own projects
* Learn how does it works **"inside"**
* Learn **C++**

## Why should I choose it?

Main idea is to create:

* Reliable Key-Value storage
* Simple usage
* Fast and reliable algorithm for getting and setting elements

### Main algorithm:

1. Init reads db
2. It saves data into deafult hash-map that storages at DRAM
3. Every new elements set at the end of the file
4. Every changes also set at the EOF
5. Every deletions also sets at the EOF as thomstone
6. When proccess close it saves all data into new db file (rewrite it without thomstones and dublicates)

This simple idea saves our data in accidents and allows get, set and delete values by O(1)

### But there are many different Key-value storages that use this idea.

That is why I implemented one more. It is more compact and useful for special type of projects that take simple and fast work with db

<u>Take in touch!</u>