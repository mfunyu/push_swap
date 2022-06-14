# push_swap
### 42 Tokyo Project Level 2
[![mfunyu's 42 push_swap Score](https://badge42.vercel.app/api/v2/cl39q9bth003509lhnivqm9hg/project/2125515)](https://github.com/JaeSeoKim/badge42)
# Usage

## push_swap
### Compilation
```
make
```

### Run (Display result)
```
./push_swap 3 5 4 2 1
```
### Show sort process
> Press `Enter` key at the beginning for `-a` and `-c` to adjust for the terminal size
- Example
  ```
  ./push_swap -a 3 1 6 10 9 5 8 7 2 4
  ```

| flag  | functions | 
|  :---:    | :---      |
| `-a` | Autoplay sort process |
| `-c` | Display sort process step by step controlled by pressing `Enter` key |
| `-v` | Output all sort process result |


## checker
### Compilation
```
make checker
```

### Run
```
./checker 1 5 2 4 3
```
1. Enter operations each separated by a line break
3. Press `Ctrl-D` at the end
- Example
	- Valid case
  ```
	$> ./checker 1 5 2 4 3
	pb
	ra
	pb
	sa
	pa
	pa
	OK
	```
  - Invalid case
  ```
	$> ./checker 1 5 2 4 3
	pb 
	rra
	rb
	sa
	ra
	KO
	```


# Project Details

## Operations Allowed

| operation | instruction |
| -- | -- | 
| sa (swap a) | Swap the first 2 elements at the top of stack a.<br>Do nothing if there is only one or no elements. |
| sb (swap b) | Swap the first 2 elements at the top of stack b.<br>Do nothing if there is only one or no elements. |
| ss  | sa and sb at the same time. |
| pa (push a) | Take the first element at the top of b and put it at the top of a.<br>Do nothing if b is empty. |
| pb (push b) | Take the first element at the top of a and put it at the top of b.<br>Do nothing if a is empty. |
| ra (rotate a) | Shift up all elements of stack a by 1.<br>The first element becomes the last one. |
| rb (rotate b) | Shift up all elements of stack b by 1.<br>The first element becomes the last one. |
| rr  | ra and rb at the same time. |
| rra (reverse rotate a) | Shift down all elements of stack a by 1.<br>The last element becomes the first one. |
| rrb (reverse rotate b) | Shift down all elements of stack b by 1.<br>The last element becomes the first one. |
| rrr  | rra and rrb at the same time. |
