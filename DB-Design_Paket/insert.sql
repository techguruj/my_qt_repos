use projekte;
--Abteilung------------------------------------------------------
insert into abteilung(abt_nr, abt_name, abt_stadt)
values('a1','Beratung','München');

--oder so...ohne Feldnamen, wenn sowieso alle Felder gefüllt werden müssen
insert into abteilung  
values('a2','Diagnose','München');

insert into abteilung  
values('a3','Freigabe','Stuttgart');

--Projekt-------------------------------------------------------
insert into projekt  
values('p1','Apollo',120000);

insert into projekt  
values('p2','Gemini',95000);

insert into projekt  
values('p3','Merkur',186500);

--Mitarbeiter----------------------------------------------------------
insert into mitarbeiter
values(25348,'Keller','Hans','a3');

insert into mitarbeiter
values(10102,'Huber','Petra','a3');

insert into mitarbeiter
values(18316,'Müller','Gabriele','a1');

insert into mitarbeiter
values(29346,'Probst','Andreas','a2');

insert into mitarbeiter
values(9031,'Meier','Rainer','a2');

insert into mitarbeiter
values(2581,'Kaufmann','Brigitte','a2');

insert into mitarbeiter
values(28559,'Mozer','Sibille','a1');

--Arbeiten-------------------------------------------------------------
set dateformat dmy; --Datumsformat auf deutsches Format einstellen

insert into arbeiten
values(10102,'p1','Projektleiter','01.10.2019');

insert into arbeiten
values(10102,'p3','Gruppenleiter','01.01.2020');

insert into arbeiten
values(25348,'p2','Sachbearbeiter','15.02.2019');

insert into arbeiten
values(18316,'p2',null,'01.06.2020');

insert into arbeiten
values(29346,'p2',null,'15.12.2018');

insert into arbeiten
values(2581,'p3','Projektleiter','15.10.2020');

insert into arbeiten
values(9031,'p1','Gruppenleiter','15.04.2020');

insert into arbeiten
values(28559,'p1',null,'01.08.2019');

insert into arbeiten
values(28559,'p2','Sachbearbeiter','01.02.2020');

insert into arbeiten
values(9031,'p3','Sachbearbeiter','15.11.2019');

insert into arbeiten
values(29346,'p1','Sachbearbeiter','01.04.2020');
