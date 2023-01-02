# Reflow

## Git Submodules

source: https://devconnected.com/how-to-add-and-update-git-submodules/

### Adding git submodule¨

-> https://stackoverflow.com/questions/43761594/cmake-and-using-git-submodule-for-dependence-projects


```
git submodule add <remote_url> <destination_folder>
git commit -m "Added the submodule to the project."
git push
```

### update git submodule

```
git submodule update --init --recursive
```