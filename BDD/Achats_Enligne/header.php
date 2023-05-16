<?php 
include "connexion_BD/connexion.php";
if(isset($_SESSION['id']))
{
?>
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
			
				<form>
					<input type="search" placeholder="Rechercher">
				</form>
				<p class="link"><a href="panier.php"><i class="fas fa-shopping-cart"></i></a>
					<a href="panier.php" style="background-color:#D98880 ;font-size: 12px; border-radius: 100%; padding:2px ; margin-left:-5px;"><?php 
								$utl=$_SESSION['id'];
								$req="exec ps_Nombre_Article_dans_panier '$utl'";
								$res=sqlsrv_query($conn,$req);
								$row=sqlsrv_fetch_array($res,SQLSRV_FETCH_ASSOC);
								
									echo $row['NbrArticle'];
								
								?></a></p>
				<p class="link">
					<a href="connexion_BD/logout.php" style="color: black;">
						<i class="fas fa-sign-out-alt"></i>
             		</a>
				</p>
				
			</div>
		</nav>
</body>
</html>
<?php
}
else {
	header("Location :index.php");
}