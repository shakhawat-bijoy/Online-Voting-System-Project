<div class="container">
  <h1 align="center">Shakhawat Hossain Bijoy</h1>
  <h2 align="center">ID: 231071041</h2>
  <h2 align="center">Dept.: CSE</h2>
  <h3 align="center">Project Name:</h3>

# Online Voting System



This repository contains a basic console-based online voting system implemented in C++. The system allows users to register as voters, cast votes, view the election winner, and provides an admin panel for managing the system.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Usage](#usage)
- [Functions](#functions)
- [Compilation](#compilation)

## Overview

This C++ program implements a simple online voting system with functionalities for voter registration, voting, viewing the winner, and an admin panel for managing the system. It uses a console-based interface for interaction.

## Features

- **Register Voter**: Allows users to register as voters by providing their NID, name, and birth date.
- **Vote**: Allows registered voters to cast their vote for one of the two candidates.
- **View Winner**: Displays the current winner based on the vote counts.
- **Admin Panel**: Allows the admin to view registered voters and vote counts, protected by a password.

## Usage

### Main Menu Options

1. **Register Voter**: Register a new voter by entering NID, name, and birth date.
2. **Vote**: Cast a vote by providing NID, name, and birth date to verify voter registration.
3. **View Winner**: View the candidate with the most votes or if there is a tie.
4. **Admin Panel**: Access the admin panel to view registered voters and vote counts (password protected).
5. **Exit**: Exit the voting system.

### Admin Panel Options

1. **View Voters**: Display a list of all registered voters.
2. **View Votes**: Display the vote counts for each candidate.
3. **Back to Main Menu**: Return to the main menu.

## Functions

### `registerVoter()`

- Prompts the user to enter NID, name, and birth date.
- Adds the voter to the list if the maximum number of voters is not reached.
- Displays a message indicating successful registration or if the maximum number of voters is reached.

### `vote()`

- Prompts the user to enter NID, name, and birth date.
- Checks if the entered information matches any registered voter.
- If registered, allows the voter to cast a vote for one of the two candidates.
- If not registered, informs the user they are not eligible to vote.

### `viewWinner()`

- Displays the winner based on the current vote counts.
- Handles the case of a tie between the candidates.

### `adminPanel()`

- Prompts the user to enter the admin password.
- Displays the admin menu if the password is correct.
- Allows the admin to view registered voters, view vote counts, or return to the main menu.

### `viewVoters()`

- Displays the list of registered voters.

### `viewVotes()`

- Displays the vote counts for each candidate.

## Compilation

To compile and run the program, use a C++ compiler like `g++`.




  

  <h3 align="center">Connect with me:</h3>
  <p align="left" class="social-links">
    <a href="https://fb.com/bijoy1x" target="blank">
      <img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/facebook.svg" alt="bijoy1x" height="30" width="40" />
      Shakhawat Bijoy
    </a>
  </p>
  <p align="left" class="social-links">
    <a href="mailto:shakhawatbijoy1@gmail.com">Email Me</a>
  </p>

  <h3 align="left">Languages and Tools:</h3>
  <p align="left">
    <a href="https://isocpp.org/" target="_blank" rel="noreferrer">
      <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/cplusplus/cplusplus-original.svg" alt="c++" width="40" height="40"/>
    </a>
  </p>
</div>
