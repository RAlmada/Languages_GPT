# Exercise 1

def check_score_e1(score):
	winning_score = 79
	return score >= winning_score

print("E1: You're a winner") if check_score_e1(100) else print("E1: You lose.")


# Exercise 2

def check_score_e2(score):
	result = "not a"
	pro_win = 92
	int_win = 86
	beg_win = 76

	if score >= pro_win:
		result = "a PRO"
	elif score >= int_win:
		result = "an INTERMEDIATE"
	elif score >= beg_win:
		result = "a BEGINNER"

	return result


print(f"E2: You're {check_score_e2(88)} winner!")


# Exercise 3

def check_scores_e3(scores):
	for i, score in enumerate(scores):
		if score > 85:
			print(f"E3: {i}: You passed")
		else:
			print(f"E3: {i}: You failed")	

player_scores = [77, 85, 93, 100, 87]
check_scores_e3(player_scores)


# Exercise 4

import random

def play_game_e4():
	while True:
		try:
			guess = input("Guess a number between 1 and 10: ").strip()
			if guess.lower() == 'q':
				break

			guess = int(guess)
			print(f"\nYou guessed: {guess}")

			if 1 <= guess <= 10:
				answer = random.randint(1, 10)

				if guess == answer:
					print("You guessed correctly!")
				else:
					print(f"So close! The correct answer was {answer}")
			else:
				print("Please keep your guess between 1 and 10")

		except ValueError:
			print("Please only input a number between 1 and 10.")


play_game_e4()


# Exercise 5

def print_leaderboard(scores):
	sorted_scores = sorted(scores, reverse=True)

	print("E5: Leaderboard")

	for i, score in enumerate(sorted_scores):
		print(f"{i + 1}. {score}")

print_leaderboard(player_scores)
