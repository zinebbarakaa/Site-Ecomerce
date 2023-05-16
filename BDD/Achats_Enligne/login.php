<?php
session_start();
include "connexion_BD/connexion.php";



	if(isset($_POST['email']) && isset($_POST['pass']))
{	
   $email=htmlentities(trim($_POST['email']));
	$pass=htmlentities(trim($_POST['pass']));
	if(empty($email))
		{
	      header("Location: connecter.php?erreur=Email incorrecte!");
		  exit();
		}
	elseif (empty($pass)) 
		{
			header("Location: connecter.php?erreur=Mot de passe incorrecte!");
		    exit();
		}
	else
		{
			$sql = "exec ps_Login '$email','$pass'";
			$params = array();
			$options =  array( "Scrollable" => SQLSRV_CURSOR_KEYSET );
			$res = sqlsrv_query($conn,$sql,$params ,$options);
			$row_count = sqlsrv_num_rows( $res);

						
						if($row_count===1)
							{
								$row=sqlsrv_fetch_array($res,SQLSRV_FETCH_ASSOC);// routorne le resulat sous forme d'un array
								
								$use=trim($row['TypeUtilisateur']);
								if($use=="AD")
									{
										$_SESSION['id']=$row['IdUtilisateur'];
										header("Location: Admin/");
									}
								else 
									{
									$_SESSION['prenom']=$row['PrenomUtilisateur'];
									$_SESSION['nom']=$row['NomUtilisateur'];
									$_SESSION['tel']=$row['TelUtilisateur'];
									$_SESSION['id']=$row['IdUtilisateur'];
										header("Location: home.php");
									}		
				
							}
							else {
								header("Location: connecter.php?erreur=Ce Compte n'existe pas! Vous voulez créer un nouveau compte!");
				   	 			exit();

							}

		}	
			
}		

else 
{
	header("Location: connecter.php?erreur");
	exit();
}



?>


