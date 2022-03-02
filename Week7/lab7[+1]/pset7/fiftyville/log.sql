-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT description FROM crime_scene_reports WHERE year = 2020 AND day = 28 AND month = 7 AND street LIKE "%Chamberlin%";
--Here i want to see at wicht hour the crime happened.
SELECT DISTINCT(name) FROM interviews WHERE year = 2020 AND month = 7 AND day = 28 AND transcript LIKE "%courthouse%";
-- Here i wanna to know the name of the wittness:Ruth, Eugene, Raymond
SELECT transcript FROM interviews WHERE name = 'Ruth';
-- I wanna to get the important information of Ruth statement.
-- The tief drove away from courthouse parking lot.
-- I need to get all cars the leave the parking lot in the time frame at the day of the crime.
SELECT transcript FROM interviews WHERE name = 'Eugene';
-- I wanna to get the important information of Eugene statement.
-- The thief get some money at the ATM on Fifer Streetat the day of the crime
SELECT transcript FROM interviews WHERE name = 'Raymond';
-- I wanna to get the important information of Raymond statement.
-- The tief has a call less than 60 s
-- The thief flight away at 29 Juli 2020 at the morning from fiftyville.
SELECT license_plate FROM courthouse_security_logs WHERE year =2020 AND month = 7 AND day = 28 AND hour= 10 AND minute LIKE "1%" AND activity ='exit';
-- I wanna to get the license_plate from the vehicles the left the parking lot in the time frame of the crime.
--5P2BI95
--94KL13X
--6P58WS2
--4328GD8
SELECT account_number FROM atm_transactions WHERE atm_location LIKE "%Fifer Street%" AND year=2020 AND month=7 AND day=28 AND transaction_type = 'withdraw';
-- I wanna the account number from the accounts that withdraw money at the day of the crime at the Fifer Street ATM.
--28500762
--28296815
--76054385
--49610011
--16153065
--25506511
--81061156
--26013199
SELECT name FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE atm_location LIKE "%Fifer Street%" AND year=2020 AND month=7 AND day=28 AND transaction_type = 'withdraw');
--I wanna of the people from the account numbers.
--Bobby
--Elizabeth
--Victoria
--Madison
--Roy
--Danielle
--Russell
--Ernest
SELECT  caller FROM phone_calls WHERE year=2020 AND month=7 AND day=28 AND duration BETWEEN 0 AND 60;
-- I wanna all the numbers that made a call at the day of thecrime with a duration less than 1 min
--(130) 555-0289
--(499) 555-9472
--(367) 555-5533
--(609) 555-5876
--(499) 555-9472
--(286) 555-6063
--(770) 555-1861
--(031) 555-6622
--(826) 555-1652
--(338) 555-6650
SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year=2020 AND month=7 AND day=28 AND duration BETWEEN 0 AND 60 );
--Bobby
--Roger
--Victoria
--Madison
--Russell
--Evelyn
--Kathryn
--Ernest
--Kimberly
SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM courthouse_security_logs WHERE year =2020 AND month = 7 AND day = 28 AND hour= 10 AND minute LIKE "1%" AND activity ='exit');
--Patrick
--Amber
--Elizabeth
--Roger
--Madison
--Danielle
--Russell
--Evelyn
--Ernest
SELECT id FROM flights WHERE year=2020 AND month=7 AND day=29 AND origin_airport_id IN (SELECT id FROM airports WHERE city LIKE "%Fiftyville%") AND hour BETWEEN 0 AND 8;
--Getting the flight the left fiftyville at 29 Juli in the morning
--36
SELECT name FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id=36);
--Getting the name of persons in the flight
--Bobby
--Roger
--Madison
--Danielle
--Evelyn
--Edward
--Ernest !!Thief!!
--Doris
SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year=2020 AND month=7 AND day=28 AND duration BETWEEN 0 AND 60 ) AND license_plate IN (SELECT license_plate FROM courthouse_security_logs WHERE year =2020 AND month = 7 AND day = 28 AND hour= 10 AND minute LIKE "1%" AND activity ='exit') AND passport_number IN (SELECT passport_number FROM passengers WHERE flight_id=36);
--Getting the Thief name combining all queries
--Thief: Ernest
SELECT destination_airport_id FROM flights WHERE  id = 36;
--Getting the id of the airport destination
--4
SELECT city FROM airports WHERE id =4;
--getting the disnation
--London
SELECT name FROM people WHERE phone_number = (SELECT receiver FROM phone_calls WHERE caller =(SELECT phone_number FROM people WHERE name = "Ernest") AND year=2020 AND month=7 AND day=28 AND duration BETWEEN 0 AND 60);
-- Getting the accomplice
--Berthold
