// Exercise 1

function checkScoreE1(score: number) {
  const winningScore = 79;
  return score >= winningScore;
}

console.log(`E1. You are a ${checkScoreE1(88) ? "winner" : "loser"}.`);
console.log(`E1. You are a ${checkScoreE1(77) ? "winner" : "loser"}.`);

console.log();

// Exercise 2

function checkScoreE2(score: number) {
  const proScore = 95;
  const intScore = 85;
  const begScore = 75;
  let result = "loser";

  if (score >= proScore) {
    result = "Professional";
  } else if (score >= intScore) {
    result = "Intermediate";
  } else if (score >= begScore) {
    result = "Beginner";
  }

  return result;
}

console.log(`E2. You are a ${checkScoreE2(99)}`);
console.log(`E2. You are a ${checkScoreE2(89)}`);
console.log(`E2. You are a ${checkScoreE2(79)}`);
console.log(`E2. You are a ${checkScoreE2(69)}`);

console.log();

// Exercise 3

function checkScoresE3(scores: number[]) {
  const passingScore = 75;

  scores.forEach((score, idx) => {
    console.log(`E3. ${idx + 1}: You ${score >= passingScore ? "passed" : "failed"}`);
  });
}

const playerScores = [45, 75, 82, 74, 99];
checkScoresE3(playerScores);

console.log();

// Exercise 4

import * as readline from "readline";

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function getUserInput(question: string): Promise<string> {
  return new Promise((resolve) => {
    rl.question(question, (answer) => {
      resolve(answer);
      // rl.close();
    });
  });
}

async function guessingGameE4() {
  const min = 1;
  const max = 10;
  let done = false;

  while (!done) {
    await getUserInput(`Enter a number between ${min} and ${max}:`).then(userInput => {
      if (userInput !== null) {
        const numberInput = Number(userInput.trim());

        if (!isNaN(numberInput) && numberInput >= min && numberInput <= max) {
          const answer = Math.floor(Math.random() * (max - min + 1)) + min;

          if (numberInput === answer) {
            console.log("You guessed correct!");
            done = true;
          } else {
            console.log(`So close! Correct answer: ${answer}`);
          }
        } else if (userInput.toLowerCase() === 'q') {
          done = true;
        } else {
          console.log(`Please input a number between ${min} and ${max}`);
        }
      } else {
        console.log(`Please input a number between ${min} and ${max}`);
      }
    });
  }

  rl.close();
}

guessingGameE4().then(() => {
  console.log();

  // Exercise 5

  function leaderboardE5(scores: number[]) {
    const sortedScores = [...scores].sort((a, b) => b - a);

    sortedScores.forEach((score, idx) => console.log(`E5. ${idx + 1}: ${score}`));
  }

  leaderboardE5(playerScores);
});
