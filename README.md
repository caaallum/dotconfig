# dotconfig

Manage linux config files 

## Plan

```
dotfiles
L .config
    L nvim
    L bspwm
    L ...
L .local
    L ...
L home
    L .bashrc
    L ...
```

```bash
$ cd /path/to/dotfiles
$ dotconfig -i
```
or
```bash
$ dotconfig -C /path/to/dotfiles -i
```

Symbolic links will be created in home directory of current user

## TODO
- [x] Command line options parsing
- [ ] Create links
- [ ] Remove links
- [ ] Create single/specified links
- [ ] Remove single/specified links
- [ ] List installed configs
- [ ] Detect already installed config. Give option to backup or override
