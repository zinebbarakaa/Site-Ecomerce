
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title></title>
	<link rel="stylesheet" href="https://pro.fontawesome.com/releases/v5.10.0/css/all.css" integrity="sha384-AYmEC3Yw5cVb3ZcuHtOA93w35dYTsvhLPVnYs9eStHfGJvOvKxVfELGroGkvsg+p" crossorigin="anonymous"/>
	<style type="text/css">
		nav {
				display: flex;
				flex-wrap: wrap;
				justify-content:space-between;
				padding: 20px;
				background-color: #fff;
				position: sticky;
				top: 0;

			}
		nav h1 {
			font-size: 20px;
		}	
		nav .ong{
			display: flex;
			flex-wrap: wrap;
		}
		nav .ong p{
			font-size: 17px;
			margin-right: 15px;
			cursor: pointer; <!-- kay7t lyed 3la p-->

		}
		nav .ong input {
			margin: 8px 20px;
			padding: 15px;
			border-radius: 30px;
			border: none;
			outline: none;
			background-color: #f2f2f2;


		}
		@media screen and (max-width: 640px)
		{
			nav .ong .link, nav h1 {
				display: none;
			}
		}
		nav .ong a 
		{
			text-decoration: none;
			color: #000;
		}
		.login
		{
			background-color:  #eb7371;
			padding-left: 5px;
			padding-right: 5px;
			border-radius: 5px;
			


		}
		.login p {
			color: #fff;
		}
		header {
			display: flex;
			justify-content: center;
			align-items: center;
			flex-direction: column;
		}
		header h1{
			font-size: 50px;
			max-width: 600px;
			text-align: center;
		}
		table tr td {
			text-align: center;
			margin-left: -5px;			
		}
		.reduction {
			display: flex;
			background-color: #000;
			font-size: 50px;
			color: #fff;
		}
		.reduction div{
			width: 33.33vw;
			text-align: center;
		}
		span {
			color: #eb7371;
			cursor: pointer;
		}
		table {
			font-size: 20px;
			margin: 40px;
		}
		td {
			padding: 20px;
		}
		.image{
			display: flex;

		}

		.image img{
			width: 30vw;
			height: 50vw;
			margin: 10vw;
		}
		.titre_cat
		{text-align: center;
			font-weight: bold;
			text-decoration: underline;
			font-size: 20px;
		}
		
		
	</style>
</head>
<body style="margin: 0px; padding: 0px; font-family: sans-serif,Open Sans;">
<nav>
			<h1>Boutique.net</h1>
			<div class="ong">
				<a href="Nouveautés.php"><p class="link">Nouveautés</p></a>
				<a href="Hommes.php"><p class="link">Hommes</p></a>
				<a href="Femmes.php"><p class="link">Femmes</p></a>
				<a href="Enfants.php"><p class="link">Enfants</p></a>
				<p class="login"><a href="connecter.php">Se Connecter</a></p>
				<p class="login"><a href="inscreption.php">Créer un Compte</a></p>					
			</div>
</nav>
<header>
	<h1>Bienvenue sur <span>Boutique.net</span>,<br>la boutique d'achat des vêtements en ligne  N°1 au Maroc !</h1>
</header>
<div class="reduction">
	<div>-5%</div>
	<div>-20%</div>
	<div>-30%</div>
</div>
<table>
	<tr>
		<td > La meilleur qualité et prix des vetements pour toutes les genres Femmes,Hommes et Enfants avec des Tailles différentes... à portée de clic !</td>
	</tr>
	<tr>
		<td><span>Boutique.net </span>est un site Ecomerce morocain qui offre des articles disponible dans différents styles,couleurs et matériaux.</td>
	</tr>
	<tr>
		<td><span>Boutique.net </span>est un site Ecomerce morocain qui offre la livraisoon à plusieurs ville du Maroc.</td>
	</tr>
</table>
<div class="catalogues">
	<div class="titre_cat">CATALOGUE POUR LES ENFANTS.</a></div>
	<div class="image">
		<img src="IMAGES\enf_robe1.png">
		<img src="IMAGES\enf_robe.png">
	</div>
	
</div>
<div class="catalogues">
	<div class="titre_cat">CATALOGUE POUR LES FEMMES.</a></div>
	<div class="image">	
		<img src="IMAGES\Robe_Vert.jpg">
		<img src="IMAGES\robeNoire.png">
	</div>
	
</div>
<div class="catalogues">
	<div class="titre_cat">CATALOGUE POUR LES HOMMES.</div>
	<div class="image">
		<img src="IMAGES\pon_marron.png">
		<img src="IMAGES\IMG-20220124-WA0024-1.jpg">
	</div>
</div>

<?php

	include 'footer.php'; 
?>

</body>
</html>